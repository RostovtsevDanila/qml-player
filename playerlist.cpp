#include "playerlist.h"

static QString PATH = QDir::homePath();
//static QString PATHH = QStandardPaths::

PlayerList::PlayerList(QObject *parent) : QAbstractListModel(parent)
{
    //    m_data.append("old");
    //    m_data.append("another old");
    qDebug() << PATH;
    QDir way(PATH);
    QStringList filters;
    filters << "*.mp3";
    m_data = way.entryInfoList(filters, QDir::AllEntries | QDir::NoDotAndDotDot);
}

QVariant PlayerList::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case Name:
        return m_data[index.row()].fileName();
        //            return QVariant(index.row() < 2 ? "orange" : "skyblue");
//    case Duration:
//        return m_data;
    default:
        return QVariant();
    }
    //    switch (role) {
    //    case ColorRole:
    //        return QVariant(index.row() < 2 ? "orange" : "skyblue");
    //    case TextRole:
    //        return m_data.at(index.row());
    //    default:
    //        return QVariant();
    //    }
}

int PlayerList::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return m_data.size();
}


QHash<int, QByteArray> PlayerList::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[Name] = "name";
//            roles[Duration] = "duration";
    //    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    //    roles[ColorRole] = "color";
    //    roles[TextRole] = "text";
    return roles;
}

//void PlayerList::add()
//{
//    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
//    m_data.append("new");
//    endInsertRows();

//    m_data[0] = QString("Size: %1").arg(m_data.size());
//    QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
//    emit dataChanged(index, index);
//}
