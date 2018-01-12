#ifndef OBFUSCATIONCONFIG_H
#define OBFUSCATIONCONFIG_H

#include <QDialog>

namespace Ui
{
class MirageConfig;
}
class WalletModel;

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class MirageConfig : public QDialog
{
    Q_OBJECT

public:
    MirageConfig(QWidget* parent = 0);
    ~MirageConfig();

    void setModel(WalletModel* model);


private:
    Ui::MirageConfig* ui;
    WalletModel* model;
    void configure(bool enabled, int coins, int rounds);

private slots:

    void clickBasic();
    void clickHigh();
    void clickMax();
};

#endif // OBFUSCATIONCONFIG_H
