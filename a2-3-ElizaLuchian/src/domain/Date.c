//
// Created by 40745 on 16/03/2024.
//

#include "Date.h"

Date CreateDate(int day, int month, int year) {

    Date data;
    data.day = day;
    data.month = month;
    data.year = year;
    return data;
}
int IsGreaterDate(Date d1, Date d2) {
    int days1 = (d1.year) * 365 + (d1.month) * 31 + (d1.day);
    int days2 = (d2.year) * 365 + (d2.month) * 31 + (d2.day);
    if (days1 > days2)
        return 1;
    return 0;

}