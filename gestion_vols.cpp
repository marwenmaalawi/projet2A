#include "gestion_vols.h"

gestion_vols::gestion_vols(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant gestion_vols::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex gestion_vols::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex gestion_vols::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int gestion_vols::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int gestion_vols::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant gestion_vols::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
