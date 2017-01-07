#ifndef SIMCONNECTION_H
#define SIMCONNECTION_H

#include <array>
#include <QObject>
#include <QVector2D>
#include <QList>

class SimConnection : public QObject
{
	Q_OBJECT

public:
	SimConnection(QObject *parent);
	~SimConnection();
	QVector2D pos;
	float extension;
	const float baseLength = 100;
	std::array<QVector2D, 2> conNodes;
	float tension;
	

private:
	
};

#endif // SIMCONNECTION_H
