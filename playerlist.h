#ifndef PLAYERLIST_H
#define PLAYERLIST_H

#include <QObject>
#include <QAbstractListModel>
#include <QStringList>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>

class PlayerList : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        Name,
//        Duration
    };
//    enum Roles {
//        ColorRole = Qt::UserRole + 1,
//        TextRole
//    };

    PlayerList(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex& index, int Role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

//    Q_INVOKABLE void add();

private:
    QList<QFileInfo> m_data;
};

#endif // PLAYERLIST_H
