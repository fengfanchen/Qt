#include "precompiled.h"
#include "user.h"
#include <QxOrm_Impl.h>

QX_REGISTER_CPP_QX_DEMO(User)

namespace qx{

    template <> void register_class(QxClass<User> &t){

        t.id(&User::id, "id");
        t.data(&User::age, "age");
        t.data(&User::name, "name");
        t.data(&User::capacity, "capacity");
    }
}
