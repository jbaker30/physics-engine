#ifndef JELLYSQUARE_H
#define JELLYSQUARE_H

#include <QtWidgets/QMainWindow>
#include "ui_jellysquare.h"
#include <QTimer>
#include <simnode.h>
#include <simconnection.h>
#include <customrender.h>

//class CustomRender;

class JellySquare : public QMainWindow
{
	Q_OBJECT

public:
	JellySquare(QWidget *parent = 0);
	~JellySquare();
	SimNode * node;
	SimNode * draggedNode;
	int lookAtMe;

private:
	Ui::JellySquareClass ui;

public slots:
	void Update();
};

#endif // JELLYSQUARE_H
