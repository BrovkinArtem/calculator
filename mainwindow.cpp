#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;
double num_second;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0 ,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plus_minus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_proc,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->pushButton_div->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if (ui->label->text().contains(".") && button->text() == "стёр, Хозяин"){
        new_label = ui->label->text() + button->text();
    } else {

    all_numbers = (ui->label->text() + button-> text()).toDouble();
    new_label = QString::number(all_numbers);
    }
    ui->label->setText(new_label);
}

    void MainWindow::on_pushButton_dot_clicked()
{
     if(!(ui->label->text().contains('.')))
     ui->label->setText(ui->label->text() + ".");

}

    void MainWindow::operations()
    {
        QPushButton *button = (QPushButton *)sender();

        double all_numbers;
        QString new_label;

        if(button->text() == "+/-"){
        all_numbers = (ui->label->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->label->setText(new_label);
    } else if(button->text() == "%"){
            all_numbers = (ui->label->text()).toDouble();
            all_numbers = all_numbers * 0.01;
            new_label = QString::number(all_numbers, 'g', 15);

            ui->label->setText(new_label);
        }
    }

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();

    num_first = ui->label->text().toDouble();
    ui->label->setText("");
    button->setChecked(true);
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_div->setChecked(false);
    ui->pushButton_mult->setChecked(false);

    ui->label->setText("стёр, Хозяин");
}

void MainWindow::on_pushButton_result_clicked()
{
    double label_number, num_second;
    QString new_label;

    num_second = ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked()) {
        label_number = num_first + num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->label->setText(new_label);
                ui->pushButton_plus->setChecked(false);
    } else if(ui->pushButton_minus->isChecked()) {
        label_number = num_first - num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->label->setText(new_label);
                ui->pushButton_minus->setChecked(false);

    } else if(ui->pushButton_div->isChecked()) {
        if (num_second == 0) {
            ui->label->setText("раз такой умный сам делай");
        } else {
        label_number = num_first / num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->label->setText(new_label);
        }
                ui->pushButton_div->setChecked(false);

    } else if(ui->pushButton_mult->isChecked()) {
        label_number = num_first * num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->label->setText(new_label);
                ui->pushButton_mult->setChecked(false);
    }
}
