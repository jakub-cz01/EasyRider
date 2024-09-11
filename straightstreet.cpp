#include "straightstreet.h"
#include <QPixmap>
StraightStreet::StraightStreet(bool vertical, int row, int column, int size) : StreetMapNode(row, column, size) {
    if (vertical) {
        setPixmap(QPixmap(":/textures/roads/v_road.png").scaled(size, size));
    }
    else {
        setPixmap(QPixmap(":/textures/roads/h_road.png").scaled(size, size));
    }
}
