#include "mirageconfig.h"
#include "ui_mirageconfig.h"

#include "bitcoinunits.h"
#include "guiconstants.h"
#include "init.h"
#include "optionsmodel.h"
#include "walletmodel.h"

#include <QKeyEvent>
#include <QMessageBox>
#include <QPushButton>
#include <QSettings>

MirageConfig::MirageConfig(QWidget* parent) : QDialog(parent),
                                                        ui(new Ui::MirageConfig),
                                                        model(0)
{
    ui->setupUi(this);

    connect(ui->buttonBasic, SIGNAL(clicked()), this, SLOT(clickBasic()));
    connect(ui->buttonHigh, SIGNAL(clicked()), this, SLOT(clickHigh()));
    connect(ui->buttonMax, SIGNAL(clicked()), this, SLOT(clickMax()));
}

MirageConfig::~MirageConfig()
{
    delete ui;
}

void MirageConfig::setModel(WalletModel* model)
{
    this->model = model;
}

void MirageConfig::clickBasic()
{
    configure(true, 1000, 2);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("Mirage Configuration"),
        tr(
            "Mirage was successfully set to basic (%1 and 2 rounds). You can change this at any time by opening YUP's configuration screen.")
            .arg(strAmount));

    close();
}

void MirageConfig::clickHigh()
{
    configure(true, 1000, 8);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("Mirage Configuration"),
        tr(
            "Mirage was successfully set to high (%1 and 8 rounds). You can change this at any time by opening YUP's configuration screen.")
            .arg(strAmount));

    close();
}

void MirageConfig::clickMax()
{
    configure(true, 1000, 16);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("Mirage Configuration"),
        tr(
            "Mirage was successfully set to maximum (%1 and 16 rounds). You can change this at any time by opening YUP's configuration screen.")
            .arg(strAmount));

    close();
}

void MirageConfig::configure(bool enabled, int coins, int rounds)
{
    QSettings settings;

    settings.setValue("nMirageRounds", rounds);
    settings.setValue("nAnonymizeYupAmount", coins);

    nMirageRounds = rounds;
    nAnonymizeYupAmount = coins;
}
