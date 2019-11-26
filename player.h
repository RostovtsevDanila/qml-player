#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <QObject>
#include <QString>
#include <QMediaPlayer>
#include <QDir>
#include <QUrl>

class Player : public QObject
{
	Q_OBJECT

public:
	explicit Player(QObject *parent = nullptr);

	Q_INVOKABLE void playMusic();
	Q_INVOKABLE void stopMusic();
	Q_INVOKABLE void pauseMusic();

	void resumeMusic();
	void setPathToFile(QString pathToFile);
	QString getPathToFile();

signals:

public slots:

private:
	QMediaPlayer m_player;
	QString pathToFile = "/home/danila/Загрузки/Song.mp3";

};

#endif // PLAYER_H
