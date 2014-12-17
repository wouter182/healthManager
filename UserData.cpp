#include "UserData.h"

namespace BSM {
namespace Data {

UserData::UserData(QObject* parent)
: QObject(parent)
, m_id(0)
, m_height(0)
, m_gender(Unknown)
, m_activity(None)
{
}

UserData::~UserData()
{
    qDeleteAll(m_measurements);
}

uchar UserData::getId() const
{
    return m_id;
}

void UserData::setId(const uchar& id)
{
    m_id = id;
}

QDate UserData::getBirthDate() const
{
    return m_birthDate;
}

void UserData::setBirthDate(const QDate& birthDate)
{
    m_birthDate = birthDate;
}

uchar UserData::getHeight() const
{
    return m_height;
}

void UserData::setHeight(const uchar& height)
{
    m_height = height;
}

UserData::Gender UserData::getGender() const
{
    return m_gender;
}

void UserData::setGender(const UserData::Gender& gender)
{
    m_gender = gender;
}

QString UserData::getGenderString() const
{
    switch (m_gender)
    {
        case Male:
            return tr("M");
        case Female:
            return tr("F");
        default:
            return "?";
    }
}

UserData::Activity UserData::getActivity() const
{
    return m_activity;
}

void UserData::setActivity(const UserData::Activity& activity)
{
    m_activity = activity;
}

UserMeasurementList& UserData::getMeasurements()
{
    return m_measurements;
}

void UserData::setMeasurements(const UserMeasurementList& measurements)
{
    m_measurements = measurements;
}

QDebug operator<<(QDebug dbg, const UserData& ud)
{
#ifdef QT_NO_DEBUG_OUTPUT
    return dbg;
#else
    dbg.nospace() << "Data::UserData("
                  << ud.m_id << ", "
                  << ud.m_birthDate.toString() << ", "
                  << ud.m_height << "cm, ";
    switch (ud.m_gender)
    {
        case UserData::Male:
            dbg.nospace() << "M";
            break;
        case UserData::Female:
            dbg.nospace() << "F";
            break;
        default:
            dbg.nospace() << "?";
            break;
    }
    dbg.nospace() << ", "
                  << (int) ud.m_activity << ", ";
    dbg.nospace() << ud.m_measurements.size() << " " << ud.m_measurements;
    dbg.nospace() << ")";
    return dbg.space();
#endif
}

QDebug operator<<(QDebug dbg, const UserData* ud)
{
#ifdef QT_NO_DEBUG_OUTPUT
    return dbg;
#else
    if (ud)
    {
        return operator<<(dbg, *ud);
    }
    dbg.nospace() << "Data::UserData()";
    return dbg.space();
#endif
}

} // namespace Data
} // namespace BSM
