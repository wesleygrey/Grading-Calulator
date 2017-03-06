#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    //returns overall grade, displays it in the ui
    void update_score();
    //returns the percent of overall score contributed by the 8 homeworks
    double hw_scores();
    //returns the higher of two midterm scores
    double higher_score(double first, double second);
    //returns the percent of overall score contributed by the 3 tests
    double test_scores();
    //returns position of lowest homework score
    size_t lowest_score(std::vector<double> scores);

    ~MainWindow();


private slots:
    //all of these dictate what happens when a slider is touched or a spin box updated
    //I know this is incredibly inefficient but I'm not sure how to genericize these functions
    void on_HW1slide_sliderMoved(int position);

    void on_HW1spin_valueChanged(int arg1);

    void on_HW2slide_sliderMoved(int position);

    void on_HW2spin_valueChanged(int arg1);

    void on_HW3slide_sliderMoved(int position);

    void on_HW3spin_valueChanged(int arg1);

    void on_HW4slide_sliderMoved(int position);

    void on_HW4spin_valueChanged(int arg1);

    void on_HW5slide_sliderMoved(int position);

    void on_HW5spin_valueChanged(int arg1);

    void on_HW6slide_valueChanged(int value);

    void on_HW6spin_valueChanged(int arg1);

    void on_HW7slide_sliderMoved(int position);

    void on_HW7spin_valueChanged(int arg1);

    void on_HW8slide_sliderMoved(int position);

    void on_HW8spin_valueChanged(int arg1);

    void on_Mid1slide_sliderMoved(int position);

    void on_Mid1spin_valueChanged(int arg1);

    void on_Mid2slide_sliderMoved(int position);

    void on_Mid2spin_valueChanged(int arg1);

    void on_Finslide_sliderMoved(int position);

    void on_Finspin_valueChanged(int arg1);

    //these two switch between the 2 grading schemes
    void on_SchemaA_clicked();

    void on_SchemaB_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
