#include "player.h"

Player::Player(QObject *parent) : QObject(parent)
{

}

void Player::playMusic()
{
	if (!m_player.isAudioAvailable()) {
		m_player.setMedia(QUrl::fromLocalFile(getPathToFile()));
		m_player.play();
	}
	else {
		resumeMusic();
	}
}

void Player::stopMusic()
{
	m_player.stop();
}

void Player::pauseMusic()
{
	m_player.pause();
}

void Player::resumeMusic()
{
	m_player.play();
}

void Player::setPathToFile(QString pathToFile)
{
	this->pathToFile = pathToFile;
}

QString Player::getPathToFile()
{
	return this->pathToFile;
}
