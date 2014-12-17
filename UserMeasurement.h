#ifndef USERMEASUREMENT_H
#define USERMEASUREMENT_H

#include <QtCore/QObject>
#include <QtCore/QDebug>
#include <QtCore/QDateTime>
#include <QtCore/QList>

namespace BSM {
namespace Data {

/*
 * \class BSM::Data::UserMeasurement
 * \brief Measurement for the user.
 *
 * This class holds the measurement data for a single weighing.
*/
class UserMeasurement : public QObject

{
    Q_OBJECT
    Q_DISABLE_COPY(UserMeasurement)

    /* The date and the time of the measurement.
     * \sa getDateTime setDateTime
    */
    Q_PROPERTY(QDateTime dateTime READ getDateTime WRITE setDateTime);

    /* The weight of the measurement (in kg).
     * \sa getWeight setWeight
    */
    Q_PROPERTY(double weight READ getWeight WRITE setWeight);

    /* The body fat percentage of the measurement.
     * \sa getBodyFatPercent setBodyFatPercent
    */
    Q_PROPERTY(double bodyFatPercent READ getBodyFatPercent WRITE setBodyFatPercent);

    /* The water percentage of the measurement.
     * \sa getWaterPercent setWaterPercent
    */
    Q_PROPERTY(double waterPercent READ getWaterPercent WRITE setWaterPercent);

    /* The muscle percentage of the measurement.
     * \sa getMusclePercent setMusclePercent
    */
    Q_PROPERTY(double musclePercent READ getMusclePercent WRITE setMusclePercent);

public:
    /* Constructor of the class.
     * \param parent the parent QObject
    */
    explicit UserMeasurement(QObject* parent = 0);

    /* Clone constructor.
     * \param other the UserData object to clone
     * \param parent the parent QObject
    */
    explicit UserMeasurement(const UserMeasurement* other, QObject* parent = 0);
    virtual ~UserMeasurement();

    /* Relative operator (greater than)
     * \param other the other UserMeasurement to compare
     * \return \c true if this UserMeasurement is greater than the \p other, \c false otherwise
    */
    virtual bool operator>(const UserMeasurement& other);

    /* Relative operator (less than)
     * \param other the other UserMeasurement to compare
     * \return \c true if this UserMeasurement is less than the \p other, \c false otherwise
    */
    virtual bool operator<(const UserMeasurement& other);

    /* Relative operator (greater or equal than)
     * \param other the other UserMeasurement to compare
     * \return \c true if this UserMeasurement is greater or equal than the \p other, \c false otherwise
    */
    virtual bool operator>=(const UserMeasurement& other);

    /* Relative operator (less or equal than)
     * \param other the other UserMeasurement to compare
     * \return \c true if this UserMeasurement is less or equal than the \p other, \c false otherwise
    */
    virtual bool operator<=(const UserMeasurement& other);

    /* Getter for the dateTime property.
     * \sa dateTime setDateTime
    */
    QDateTime getDateTime() const;

    /* Getter for the weight property.
     * \sa weight setWeight
    */
    double getWeight() const;

    /* Getter for the bodyFatPercent property.
     * \sa bodyFatPercent setBodyFatPercent
    */
    double getBodyFatPercent() const;

    /* Getter for the waterPercent property.
     * \sa waterPercent setWaterPercent
    */
    double getWaterPercent() const;

    /* Getter for the musclePercent property.
     * \sa musclePercent setMusclePercent
    */
    double getMusclePercent() const;

public slots:
    /* Setter for the dateTime property.
     * \param dateTime the new value
     * \sa dateTime getDateTime
    */
    void setDateTime(const QDateTime& dateTime);

    /* Setter for the weight property.
     * \param weight the new value
     * \sa weight getWeight
    */
    void setWeight(const double& weight);

    /* Setter for the bodyFatPercent property.
     * \param bodyFatPercent the new value
     * \sa bodyFatPercent getBodyFatPercent
    */
    void setBodyFatPercent(const double& bodyFatPercent);

    /* Setter for the waterPercent property.
     * \param waterPercent the new value
     * \sa waterPercent getWaterPercent
    */
    void setWaterPercent(const double& waterPercent);

    /* Setter for the musclePercent property.
     * \param musclePercent the new value
     * \sa musclePercent getMusclePercent
    */
    void setMusclePercent(const double& musclePercent);

protected:
    QDateTime   m_dateTime; //< dateTime property value. \sa dateTime getDateTime setDateTime
    double      m_weight; //< weight property value. \sa weight getWeight setWeight
    double      m_bodyFatPercent; //< bodyFatPercent property value. \sa bodyFatPercent getBodyFatPercent setBodyFatPercent
    double      m_waterPercent; //< waterPercent property value. \sa waterPercent getWaterPercent setWaterPercent
    double      m_musclePercent; //< musclePercent property value. \sa musclePercent getMusclePercent setMusclePercent

    friend QDebug operator<<(QDebug dbg, const UserMeasurement& um);
};

/* QDebug stream operator for UserMeasurement.
 * \param dbg the QDebug object
 * \param um the UserMeasurement object
 * \return the QDebug object
*/
QDebug operator<<(QDebug dbg, const UserMeasurement& um);

/* QDebug stream operator for UserMeasurement.
 * \param dbg the QDebug object
 * \param um the UserMeasurement object
 * \return the QDebug object
*/
QDebug operator<<(QDebug dbg, const UserMeasurement* um);

// List of measurements
typedef QList<UserMeasurement*> UserMeasurementList;

} // namespace Data
} // namespace BSM

#endif // USERMEASUREMENT_H
