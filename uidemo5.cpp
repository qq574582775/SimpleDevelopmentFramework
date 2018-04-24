#include "uidemo5.h"
#include "ui_uidemo5.h"
#include "navlistview.h"
#include "quiwidget.h"



UIDemo5::UIDemo5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UIDemo5)
{
    ui->setupUi(this);
    init();
}

UIDemo5::~UIDemo5()
{
    delete ui;
}


void UIDemo5::init()
{
    this->initForm();
    updateProjInfo();
    QUIWidget::setFormInCenter(this);
    QTimer::singleShot(100, this, SLOT(initIndex()));
    resize(QSize(1080, 600));
}


void UIDemo5::updateProjInfo()
{
    QStringList listItem;

    //标题|父节点标题(父节点为空)|是否展开|提示信息
    listItem.append("主界面||1|");

    listItem.append("1||0|");
    listItem.append("1|1||");
    listItem.append("2|1||");
    listItem.append("3|1||");

    listItem.append("2||0|");
    listItem.append("1|2||");
    listItem.append("2|2||");
    listItem.append("3|2||");
    listItem.append("4|2||");

    listItem.append("3||0|");
    listItem.append("1|3|0|");
    listItem.append("2|3|0|");
    listItem.append("3|3|0|");
    listItem.append("3||0|");
    listItem.append("1|3|0|");
    listItem.append("2|3|0|");
    listItem.append("3|3|0|");
    listItem.append("3||0|");
    listItem.append("1|3|0|");
    listItem.append("2|3|0|");
    listItem.append("3|3|0|");

    listItem.append("帮助文档||1|");

    ui->listView->setData(listItem);

    ui->listView->setColorLine(QColor(53, 53, 53));
    ui->listView->setColorBgNormal(QColor(70, 70, 70));
    ui->listView->setColorBgHover(QColor(99, 99, 99));
    ui->listView->setColorBgSelected(QColor(82, 82, 82));
    ui->listView->setColorTextNormal(QColor(250, 250, 250));
    ui->listView->setColorTextHover(QColor(200, 200, 200));
    ui->listView->setColorTextSelected(QColor(252, 252, 252));
}

void UIDemo5::initForm()
{
    this->max = false;
    this->location = this->geometry();
    this->setProperty("form", true);
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    this->setWindowTitle("SmartSolo Device Manager");
    //IconHelper::Instance()->setIcon(ui->labTitle, QChar(0xf072), 35);
    ui->labTitle->setText("DTCC");
    auto font = ui->labTitle->font();
    font.setPointSize(25);
    font.setFamily("Bauhaus 93");
    ui->labTitle->setFont(font);
    IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xF068));
    IconHelper::Instance()->setIcon(ui->btnMenu_Max, QChar(0xF067));
    IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xF00d));

    QString items = "IGU;Battery Pack;About";
    ui->widgetNavTop->setItems(items);
    ui->widgetNavTop->setHorizontal(true);
    ui->widgetNavTop->setLineWidth(5);
    ui->widgetNavTop->setSpace(60);
    ui->widgetNavTop->setLineColor(QColor(53, 53, 53));
    ui->widgetNavTop->setBgColorStart(QColor(70, 70, 70));
    ui->widgetNavTop->setBgColorEnd(QColor(70, 70, 70));
    ui->widgetNavTop->setBarColorStart(QColor(99, 99, 99));
    ui->widgetNavTop->setBarColorEnd(QColor(80, 80, 80));
    ui->widgetNavTop->setTextNormalColor(QColor(150, 150, 150));
    ui->widgetNavTop->setTextSelectColor(QColor(250, 250, 250));
}

void UIDemo5::initIndex()
{
    ui->widgetNavTop->setCurrentIndex(0);    
}

void UIDemo5::on_btnMenu_Min_clicked()
{
    showMinimized();
}

void UIDemo5::on_btnMenu_Max_clicked()
{
    if (max) {
        this->setGeometry(location);
        this->setProperty("canMove", true);
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
        this->setProperty("canMove", false);
    }

    max = !max;
}

void UIDemo5::on_btnMenu_Close_clicked()
{
    close();
}

void UIDemo5::on_listView_pressed(const QModelIndex &index)
{
    ui->label->setText(index.data().toString());
}
