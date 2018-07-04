//
// Created by alexis on 7/3/18.
//

#ifndef NX_SOFTWARE_CENTER_LOCALIZATIONUTILS_H
#define NX_SOFTWARE_CENTER_LOCALIZATIONUTILS_H

#include <entities/AppImageInfo.h>

class LocalizationUtils {
public:
    static QVariant getLocalizedValue(const QMap<QString, QVariant>& lcField);
    static QVariant getLocalizedValue(const AppImageInfo::LocalizedQString& lcField);
};

#endif //NX_SOFTWARE_CENTER_LOCALIZATIONUTILS_H
