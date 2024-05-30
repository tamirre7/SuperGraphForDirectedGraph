#ifndef GRAPH_ERROR_H
#define GRAPH_ERROR_H

#include <string>

class GraphError {
public:
    GraphError(const std::string& msg) : msg_(msg) {}
    ~GraphError() {}

    std::string getMessage() const { return msg_; }

private:
    std::string msg_;
};

#endif // GRAPH_ERROR_H
