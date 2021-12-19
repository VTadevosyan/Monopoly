/**
 * MONOPOLY
 */

#ifndef MONOPOLY_ICONMANAGER_HPP
#define MONOPOLY_ICONMANAGER_HPP

#include <vector>
#include <QString>

namespace Gui {

/// @class IconManager
/// @brief IconManager
class IconManager
{
public:
    static void create();
    static void destroy();
    static IconManager* get();

    QString getIcon(size_t ind);

private:
    void initIcons();

private:
    static IconManager* sIconManager;

private:
    IconManager();
    ~IconManager();

    std::vector<QString> m_icons;
};


}

#endif /// MONOPOLY_ICONMANAGER_HPP
