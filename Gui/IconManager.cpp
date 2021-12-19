/**
 * MONOPOLY
 */

#include "IconManager.hpp"

#include <QPixmap>


namespace Gui {

IconManager* IconManager::sIconManager = nullptr;

void IconManager::create()
{
    Q_ASSERT(sIconManager == nullptr);
    sIconManager = new IconManager;
}

void IconManager::destroy()
{
    Q_ASSERT(sIconManager != nullptr);
    delete sIconManager;
    sIconManager = nullptr;
}

IconManager* IconManager::get()
{
    Q_ASSERT(sIconManager != nullptr);
    return sIconManager;
}

IconManager::IconManager()
{
    m_icons.resize(40);
    initIcons();
}

IconManager::~IconManager()
{

}

QString IconManager::getIcon(size_t ind)
{
    if(ind < 0 || ind > m_icons.size())
        return "";
    else
         return m_icons[ind];
}

void IconManager::initIcons()
{
    m_icons[0] = "Icons/GO.png";
    m_icons[1] = "Icons/Onex.ico";
    m_icons[2] = "Icons/ChanceV.ico";
    m_icons[3] = "Icons/Globbing.ico";
    m_icons[4] = "Icons/TaxOffice.ico";
    m_icons[5] = "Icons/YerevanMall.ico";
    m_icons[6] = "Icons/UTaxi.ico";
    m_icons[7] = "Icons/ChanceV.ico";
    m_icons[8] = "Icons/YandexTaxi.ico";
    m_icons[9] = "Icons/GGTaxi.ico";
    m_icons[10] = "Icons/Jail.png";
    m_icons[11] = "Icons/IDram.ico";
    ///m_icons[12] = "Icons/ChanceHR.ico";
    m_icons[12] = "Icons/TucanTextile.ico";
    m_icons[13] = "Icons/EasyPay.ico";
    m_icons[14] = "Icons/TelCell.ico";
    m_icons[15] = "Icons/DalmaGardenMall.ico";
    m_icons[16] = "Icons/Zangi.ico";
    m_icons[17] = "Icons/ChanceHR.ico";
    m_icons[18] = "Icons/PicsArt.ico";
    m_icons[19] = "Icons/Krisp.ico";
    m_icons[20] = "Icons/FreeParking.png";
    m_icons[21] = "Icons/Beeline.ico";
    m_icons[23] = "Icons/VivaMTS.ico";
    m_icons[24] = "Icons/Ucom.ico";
    m_icons[22] = "Icons/ChanceV.ico";
    m_icons[25] = "Icons/RioMall.ico";
    m_icons[26] = "Icons/TsiranSupermarkets.ico";
    m_icons[27] = "Icons/NorZovkSupermarkets.ico";
    ///m_icons[28] = "Icons/ChanceV.ico";
    m_icons[28] = "Icons/AlexTextile.ico";
    m_icons[29] = "Icons/YerevanCitySupermarkets.ico";
    m_icons[30] = "Icons/GoToJail.png";
    m_icons[31] = "Icons/VeoliaJur.ico";
    m_icons[32] = "Icons/ChanceHL.ico";
    m_icons[33] = "Icons/GazpromArmenia.ico";
    m_icons[34] = "Icons/HEC.ico";
    m_icons[35] = "Icons/MegaMall.ico";
    m_icons[36] = "Icons/LuxuryTax.ico";
    m_icons[37] = "Icons/NoyCognac.ico";
    m_icons[38] = "Icons/ChanceHL.ico";
    m_icons[39] = "Icons/AraratCognac.ico";
}

} /// Gui namespace
