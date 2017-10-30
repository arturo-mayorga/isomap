#ifndef MANIFOLDNODE_H
#define MANIFOLDNODE_H

class ManifoldNode
{
    public:
    int id;
    double distance;
    std::vector<ManifoldNode*> children;
}

#endif