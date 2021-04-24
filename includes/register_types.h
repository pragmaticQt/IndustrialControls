#include <QCoreApplication>
#include <QQmlEngine>

#include "custom_double_validator.h"
#include "file_browser_model.h"
#include "svg_item.h"
#include "theme_loader.h"

#define QML_TYPE_I(T)  qmlRegisterType<T>("Industrial", 1, 0, #T)
#define QML_TYPE_IC(T) qmlRegisterType<T>("Industrial.Controls", 1, 0, #T)

static void registerTypes()
{
    QML_TYPE_I (FileBrowserModel);
    QML_TYPE_I (SvgItem);
    QML_TYPE_IC(CustomDoubleValidator);
    QML_TYPE_IC(ThemeLoader);
}

//Q_COREAPP_STARTUP_FUNCTION(registerTypes)
