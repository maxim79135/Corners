#include "customlabel.h"

CustomLabel::CustomLabel()
{
    
}

CustomLabel::CustomLabel(int size, int wx, int wh) {
    QFont f;
    f.setPixelSize(size);
    f.setBold(true);
    setFont(f);
    setStyleSheet("QLabel{background-color: rgba(195, 176, 145, 80);}");
    move(wx, wh);
}

void CustomLabel::keyPressEvent(QKeyEvent *event) {
    emit on_press_label();
}
