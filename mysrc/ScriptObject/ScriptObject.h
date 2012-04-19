#ifndef SCRIPT_VALUE_H
#define SCRIPT_VALUE_H

#include <string>

class ScriptObject {
public:

    enum ValueType {
        eValueType_Null,
        eValueType_Int,
        eValueType_Double,
        eValueType_String,
        eValueType_Pointer
    };

    ScriptObject();
    ScriptObject(int val);
    ScriptObject(double val);
    ScriptObject(const std::string& val);
    ScriptObject(void* val);
    
    int toInt() const;
    double toDouble() const;
    std::string toString() const;
    void* toPointer() const;

    ValueType getValueType() const;

private:
    std::string m_str;
    int m_int;
    double m_double;
    void* m_pointer;

    ValueType m_type;
};

#endif
