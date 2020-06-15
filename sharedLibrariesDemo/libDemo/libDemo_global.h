#ifndef LIBDEMO_GLOBAL_H
#define LIBDEMO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBDEMO_LIBRARY)
#  define LIBDEMO_EXPORT Q_DECL_EXPORT
#else
#  define LIBDEMO_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBDEMO_GLOBAL_H
