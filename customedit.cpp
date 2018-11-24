#include "customedit.h"

CustomEdit::CustomEdit()
{

}

CustomEdit::CustomEdit(int w, int h, int size, int wx, int wh) {
    setFixedSize(w, h);
    setMaxLength(10);
    QFont f;
    f.setPixelSize(size);
    f.setBold(true);
    setFont(f);
    setStyleSheet("QLineEdit{background-color: rgba(195, 176, 145, 80);}");
    move(wx, wh);
}
