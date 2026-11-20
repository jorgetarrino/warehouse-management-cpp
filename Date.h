//
// Created by PC on 08/03/2026.
//

#ifndef PROYECTOANAYJORGE_DATE_H
#define PROYECTOANAYJORGE_DATE_H


class Date {
    int day = 0;
    int month = 0;
    int year = 0;
public:
    Date();
    Date(int day, int month, int year);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
    int daysDiff(const Date& other) const;
    void showDate() const;
};


#endif //PROYECTOANAYJORGE_DATE_H