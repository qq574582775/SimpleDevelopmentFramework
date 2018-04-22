#include "uidemo5.h"
#include "ui_uidemo5.h"
#include "navlistview.h"
#include "quiwidget.h"

UIDemo5::UIDemo5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UIDemo5)
{
    ui->setupUi(this);
    this->initForm();
    QUIWidget::setFormInCenter(this);
    QTimer::singleShot(100, this, SLOT(initIndex()));
    resize(QSize(1080,600));
}

UIDemo5::~UIDemo5()
{
    delete ui;
}

void UIDemo5::initForm()
{
    this->max = false;
    this->location = this->geometry();
    this->setProperty("form", true);
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    this->setWindowTitle("demo");

    IconHelper::Instance()->setIcon(ui->labTitle, QChar(0xf072), 35);
    IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xF068));
    IconHelper::Instance()->setIcon(ui->btnMenu_Max, QChar(0xF067));
    IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xF00d));

    QStringList qss;
    qss.append("QLabel#labTitle{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #2AA2DA, stop:1 #12B5C9);color:#F0F0F0;}");
    qss.append("QWidget#widgetTop{background:#FFFFFF;}");
    qss.append("QWidget#widgetMain{background:#F1F3F6;}");
    qss.append("QLabel#label{color:#202020;font:50pt;}");
    qss.append("QListView#listView{background:rgb(52,73,94);border-width:0px;}");    
    this->setStyleSheet(qss.join(""));

    //标题|父节点标题(父节点为空)|是否展开|提示信息
    QStringList listItem;
    listItem.append("主界面||0|");

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

    listItem.append("帮助文档||1|");

    ui->listView->setData(listItem);
    ui->listView->setColorLine(QColor(32, 53, 74));
    ui->listView->setColorBgNormal(QColor(52, 73, 94));
    ui->listView->setColorBgHover(QColor(24, 189, 155));
    ui->listView->setColorBgSelected(QColor(24, 189, 155));
    ui->listView->setColorTextNormal(QColor(250, 250, 250));
    ui->listView->setColorTextHover(QColor(0, 0, 0));
    ui->listView->setColorTextSelected(QColor(252, 252, 252));

    QString items = "A;B;C";
    ui->widgetNavTop->setItems(items);
    ui->widgetNavTop->setHorizontal(true);
    ui->widgetNavTop->setLineWidth(5);
    ui->widgetNavTop->setSpace(100);
    ui->widgetNavTop->setLineColor(QColor(255, 107, 107));
    ui->widgetNavTop->setBgColorStart(QColor(255, 255, 255));
    ui->widgetNavTop->setBgColorEnd(QColor(255, 255, 255));
    ui->widgetNavTop->setBarColorStart(QColor(24, 189, 155));
    ui->widgetNavTop->setBarColorEnd(QColor(24, 189, 155));
    ui->widgetNavTop->setTextNormalColor(QColor(80, 80, 80));
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
