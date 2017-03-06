#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::update_score(){
    double score = 0;
    score += hw_scores();
    score += test_scores();
    //convert the double score into a QString for output
    QString percent = QString::number(score);
    percent += '%';
    ui->Percent->setText(percent);
}

double MainWindow::hw_scores()
{
    double score = 0;

    std::vector<double> scores;
    //again, I know this is terrible but I don't know how else to do this in Qt
    //convert to double to avoid round off error
    scores.push_back(double(ui->HW1spin->value())/7);
    scores.push_back(double(ui->HW2spin->value())/7);
    scores.push_back(double(ui->HW3spin->value())/7);
    scores.push_back(double(ui->HW4spin->value())/7);
    scores.push_back(double(ui->HW5spin->value())/7);
    scores.push_back(double(ui->HW6spin->value())/7);
    scores.push_back(double(ui->HW7spin->value())/7);
    scores.push_back(double(ui->HW8spin->value())/7);

    size_t lowest_pos = lowest_score(scores);

    //if the homework is not the lowest, add it to score
    for(size_t pos = 0; pos != scores.size(); ++pos){
        if(pos != lowest_pos){
            score += scores[pos];
        }
    }



    /*
    score += (ui->HW1spin->value())*0.125;
    score += (ui->HW2spin->value())*0.125;
    score += (ui->HW3spin->value())*0.125;
    score += (ui->HW4spin->value())*0.125;
    score += (ui->HW5spin->value())*0.125;
    score += (ui->HW6spin->value())*0.125;
    score += (ui->HW7spin->value())*0.125;
    score += (ui->HW8spin->value())*0.125;
    */

    score *= 0.25;

    return score;
}


double MainWindow::higher_score(double first, double second)
{
    if(first < second){
        return second;
    }
    return first;
}

double MainWindow::test_scores()
{
    double score = 0;
    //if Schema A is checked
    if(ui->SchemaA->isChecked()){
        score += (ui->Mid1spin->value())*0.2;
        score += (ui->Mid2spin->value())*0.2;
        score += (ui->Finspin->value())*0.35;
    }
    //if Schema B is checked
    else if(ui->SchemaB->isChecked()){
        score += (higher_score(ui->Mid1spin->value(), ui->Mid2spin->value()))*0.3;
        score += (ui->Finspin->value())*0.45;
    }
    return score;
}

size_t MainWindow::lowest_score(const std::vector<double> scores)
{
    size_t lowest_pos = 0;
    for(size_t pos = 0; pos != scores.size(); ++pos){
        if(scores[pos] <= scores[lowest_pos] ){
            lowest_pos = pos;
        }
    }
    return lowest_pos;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_HW1slide_sliderMoved(int position)
{
    ui->HW1spin->setValue(position);
    update_score();
}

void MainWindow::on_HW1spin_valueChanged(int arg1)
{
    ui->HW1slide->setValue(arg1);
    update_score();
}

void MainWindow::on_HW2slide_sliderMoved(int position)
{
    ui->HW2spin->setValue(position);
    update_score();
}

void MainWindow::on_HW2spin_valueChanged(int arg1)
{
    ui->HW2slide->setValue(arg1);
    update_score();
}

void MainWindow::on_HW3slide_sliderMoved(int position)
{
    ui->HW3spin->setValue(position);
    update_score();
}

void MainWindow::on_HW3spin_valueChanged(int arg1)
{
    ui->HW3slide->setValue(arg1);
    update_score();
}

void MainWindow::on_HW4slide_sliderMoved(int position)
{
    ui->HW4spin->setValue(position);
    update_score();
}

void MainWindow::on_HW4spin_valueChanged(int arg1)
{
    ui->HW4slide->setValue(arg1);
    update_score();
}

void MainWindow::on_HW5slide_sliderMoved(int position)
{
    ui->HW5spin->setValue(position);
    update_score();
}

void MainWindow::on_HW5spin_valueChanged(int arg1)
{
    ui->HW5slide->setValue(arg1);
    update_score();
}

void MainWindow::on_HW6slide_valueChanged(int position)
{
    ui->HW6spin->setValue(position);
    update_score();
}

void MainWindow::on_HW6spin_valueChanged(int arg1)
{
    ui->HW6slide->setValue(arg1);
    update_score();
}

void MainWindow::on_HW7slide_sliderMoved(int position)
{
    ui->HW7spin->setValue(position);
    update_score();
}

void MainWindow::on_HW7spin_valueChanged(int arg1)
{
    ui->HW7slide->setValue(arg1);
    update_score();
}

void MainWindow::on_HW8slide_sliderMoved(int position)
{
    ui->HW8spin->setValue(position);
    update_score();
}

void MainWindow::on_HW8spin_valueChanged(int arg1)
{
    ui->HW8slide->setValue(arg1);
    update_score();
}

void MainWindow::on_Mid1slide_sliderMoved(int position)
{
    ui->Mid1spin->setValue(position);
    update_score();
}

void MainWindow::on_Mid1spin_valueChanged(int arg1)
{
    ui->Mid1slide->setValue(arg1);
    update_score();
}

void MainWindow::on_Mid2slide_sliderMoved(int position)
{
    ui->Mid2spin->setValue(position);
    update_score();
}

void MainWindow::on_Mid2spin_valueChanged(int arg1)
{
    ui->Mid2slide->setValue(arg1);
    update_score();
}

void MainWindow::on_Finslide_sliderMoved(int position)
{
    ui->Finspin->setValue(position);
    update_score();
}

void MainWindow::on_Finspin_valueChanged(int arg1)
{
    ui->Finslide->setValue(arg1);
    update_score();
}



void MainWindow::on_SchemaA_clicked()
{
    update_score();
}

void MainWindow::on_SchemaB_clicked()
{
    update_score();
}
