#ifndef USER_H
#define USER_H

class QX_DEMO_DLL_EXPORT User{

public:
    int id;
    QString name;
    int age;
    double capacity;

    User(): id(1){}
    virtual ~User(){}
};

QX_REGISTER_PRIMARY_KEY(User, int)
QX_REGISTER_HPP_QX_DEMO(User, qx::trait::no_base_class_defined, 0)

typedef std::shared_ptr<User> User_ptr;
typedef qx::QxCollection<int, User_ptr> List_user;

#endif // USER_H
