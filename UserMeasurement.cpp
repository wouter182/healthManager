#include "UserMeasurement.h"

namespace BSM {
namespace Data {

UserMeasurement::UserMeasurement(QObject* parent)
: QObject(parent)
, m_weight(0)
, m_bodyFatPercent(0)
, m_waterPercent(0)
, m_musclePercent(0)
{
}

UserMeasurement::UserMeasurement(const UserMeasurement* other, QObject* parent)
: QObject(parent)
, m_dateTime(other->m_dateTime)
, m_weight(other->m_weight)
, m_bodyFatPercent(other->m_bodyFatPercent)
, m_waterPercent(other->m_waterPercent)
, m_musclePercent(other->m_musclePercent)
{
}

UserMeasurement::~UserMeasurement()
{
}

bool UserMeasurement::operator<(const UserMeasurement& other)
{
    return (m_dateTime < other.m_dateTime);
}

bool UserMeasurement::operator>(const UserMeasurement& other)
{
    return (m_dateTime > other.m_dateTime);
}

bool UserMeasurement::operator<=(const UserMeasurement& other)
{
    return (m_dateTime <= other.m_dateTime);
}

bool UserMeasurement::operator>=(const UserMeasurement& other)
{
    return (m_dateTime >= other.m_dateTime);
}

QDateTime UserMeasurement::getDateTime() const
{
    return m_dateTime;
}
void UserMeasurement::setDateTime(const QDateTime& dateTime)
{
    m_dateTime = dateTime;
}

double UserMeasurement::getWeight() const
{
    return m_weight;
}

void UserMeasurement::setWeight(const double& weight)
{
    m_weight = weight;
}

double UserMeasurement::getBodyFatPercent() const
{
    return m_bodyFatPercent;
}

void UserMeasurement::setBodyFatPercent(const double& bodyFatPercent)
{
    m_bodyFatPercent = bodyFatPercent;
}

double UserMeasurement::getWaterPercent() const
{
    return m_waterPercent;
}

void UserMeasurement::setWaterPercent(const double& waterPercent)
{
    m_waterPercent = waterPercent;
}

double UserMeasurement::getMusclePercent() const
{
    return m_musclePercent;
}

void UserMeasurement::setMusclePercent(const double& musclePercent)
{
    m_musclePercent = musclePercent;
}

QDebug operator<<(QDebug dbg, const UserMeasurement& um)
{
#ifdef QT_NO_DEBUG_OUTPUT
return dbg;
#else
    dbg.nospace() << "Data::UserMeasurement("
                  << um.m_dateTime.toString() << " - "
                  << um.m_weight << "kg, "
                  << um.m_bodyFatPercent << "%, "
                  << um.m_waterPercent << "%, "
                  << um.m_musclePercent << "%)";
    return dbg.space();
#endif
}

QDebug operator<<(QDebug dbg, const UserMeasurement* um)
{
#ifdef QT_NO_DEBUG_OUTPUT
    return dbg;
#else
    if (um)
    {
        return operator<<(dbg, *um);
    }
    dbg.nospace() << "Data::UserMeasurement()";
    return dbg.space();
#endif
}

} // namespace Data
} // namespace BSM
