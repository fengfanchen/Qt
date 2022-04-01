#include <QCoreApplication>
#include <QDebug>
#include "DPI.h"
#include "DPIext.h"
#include "DPItypes.h"

#define DM_SVR "127.0.0.1:5236"
#define DM_USER "SYSDBA"
#define DM_PWD "SYSDBA"

dhenv henv; /* 环境句柄 */
dhcon hcon; /* 连接句柄 */
dhstmt hstmt; /* 语句句柄 */
dhdesc hdesc; /* 描述符句柄 */
DPIRETURN rt; /* 函数返回值 */

void dpi_err_msg_print(sdint2 hndl_type, dhandle hndl)
{
    sdint4 err_code;
    sdint2 msg_len;
    sdbyte err_msg[SDBYTE_MAX];

    /* 获取错误信息集合 */
    dpi_get_diag_rec(hndl_type, hndl, 1, &err_code, err_msg, sizeof(err_msg), &msg_len);
    printf("err_msg = %s, err_code = %d\n", err_msg, err_code);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    sdint4  out_c1 = 0;
    sdbyte  out_c2[20]= { 0 };
    slength out_c1_ind = 0;
    slength out_c2_ind = 0;
    ulength row_num;

    //连接数据库
        /* 申请环境句柄 */
        rt = dpi_alloc_env(&henv);

        /* 申请连接句柄 */
        rt = dpi_alloc_con(henv, &hcon);

        /* 连接数据库服务器 */
        rt = dpi_login(hcon, (sdbyte *)DM_SVR, (sdbyte *)DM_USER, (sdbyte *)DM_PWD);
        if(!DSQL_SUCCEEDED(rt))
        {
            dpi_err_msg_print(DSQL_HANDLE_DBC, hcon);
            return rt;
        }
        printf("dpi: connect to server success!\n");


        rt = dpi_alloc_stmt(hcon, &hstmt);

        //select * from CLCC.CLCC_REGION
        qDebug() << dpi_exec_direct(hstmt, (sdbyte*) "select * from CLCC.CLCC_REGION");
        dpi_bind_col(hstmt, 1, DSQL_C_SLONG, &out_c1, sizeof(out_c1), &out_c1_ind);
        dpi_bind_col(hstmt, 2, DSQL_C_NCHAR, &out_c2, sizeof(out_c2), &out_c2_ind);

        printf("dpi: select * from table...\n");
        while(dpi_fetch(hstmt, &row_num) != DSQL_NO_DATA)
        {
            printf("c1 = %d, c2 = %s ,\n", out_c1, out_c2);
        }
        printf("dpi: select success\n");


        //断开数据库连接
        /* 断开连接 */
        rt = dpi_logout(hcon);
        if(!DSQL_SUCCEEDED(rt))
        {
            dpi_err_msg_print(DSQL_HANDLE_DBC, hcon);
        return rt;
        }
        printf( "dpi: disconnect from server success!\n" );

        /* 释放连接句柄和环境句柄 */
        rt = dpi_free_con(hcon);
        rt = dpi_free_env(henv);

        return rt;

    return a.exec();
}
