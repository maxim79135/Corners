#ifndef CUSTOMEDIT_H
#define CUSTOMEDIT_H

#include <QtWidgets>

class CustomEdit : public QLineEdit
{
public:
    CustomEdit();
    CustomEdit(int w, int h, int f, int wx, int wh);

private:
    int width;
    int height;
};

#endif // CUSTOMEDIT_H
