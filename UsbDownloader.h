#ifndef USBDOWNLOADER_H
#define USBDOWNLOADER_H

#include <QtCore/QThread>
#include <QtCore/QByteArray>

class libusb_context;

namespace BSM {
namespace Usb {

/*
 * \class BSM::Usb::UsbDownloader
 * \brief Downloader for the data from the scale.
 *
 * This class ask the scale for the data in its memory and then download them.
 * When the download is completed, a signal is emitted. A progress signal is also
 * emitted while downloading.
*/

class UsbDownloader : public QThread
{
    Q_OBJECT
    Q_DISABLE_COPY(UsbDownloader)

public:
    /* Constructor of the class.
     * \param parent the parent QObject
    */
    explicit UsbDownloader(QObject* parent = 0);
    virtual ~UsbDownloader();

signals:
    /* The download was completed.
     * \param data the data downloaded
    */
    void completed(const QByteArray& data);

    // The download cannot be completed.
    void error();

    /* The download is in progress
     * \param perc the percentage of the progress
    */
    void progress(const int perc);

protected:
    // The libusb context.
    libusb_context* ctx;

    // The starting point for the thread.
    virtual void run();
};

} // namespace Usb
} // namespace BSM

#endif // USBDOWNLOADER_H
