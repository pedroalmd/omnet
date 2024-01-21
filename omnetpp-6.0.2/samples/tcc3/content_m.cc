//
// Generated file, do not edit! Created by opp_msgtool 6.0 from content.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "content_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(ContentMsg)

ContentMsg::ContentMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

ContentMsg::ContentMsg(const ContentMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

ContentMsg::~ContentMsg()
{
}

ContentMsg& ContentMsg::operator=(const ContentMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void ContentMsg::copy(const ContentMsg& other)
{
    this->source_num = other.source_num;
    this->type = other.type;
    this->destination = other.destination;
    this->hopCount = other.hopCount;
    this->content = other.content;
    this->chunk = other.chunk;
    this->tcp_type = other.tcp_type;
    this->c_average_chunk_arr = other.c_average_chunk_arr;
    this->c_finish_dwnl_time = other.c_finish_dwnl_time;
    this->c_total_stall_time = other.c_total_stall_time;
    this->c_stall_count_size = other.c_stall_count_size;
}

void ContentMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->source_num);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->destination);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->content);
    doParsimPacking(b,this->chunk);
    doParsimPacking(b,this->tcp_type);
    doParsimPacking(b,this->c_average_chunk_arr);
    doParsimPacking(b,this->c_finish_dwnl_time);
    doParsimPacking(b,this->c_total_stall_time);
    doParsimPacking(b,this->c_stall_count_size);
}

void ContentMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->source_num);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->destination);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->content);
    doParsimUnpacking(b,this->chunk);
    doParsimUnpacking(b,this->tcp_type);
    doParsimUnpacking(b,this->c_average_chunk_arr);
    doParsimUnpacking(b,this->c_finish_dwnl_time);
    doParsimUnpacking(b,this->c_total_stall_time);
    doParsimUnpacking(b,this->c_stall_count_size);
}

int ContentMsg::getSource_num() const
{
    return this->source_num;
}

void ContentMsg::setSource_num(int source_num)
{
    this->source_num = source_num;
}

char ContentMsg::getType() const
{
    return this->type;
}

void ContentMsg::setType(char type)
{
    this->type = type;
}

int ContentMsg::getDestination() const
{
    return this->destination;
}

void ContentMsg::setDestination(int destination)
{
    this->destination = destination;
}

int ContentMsg::getHopCount() const
{
    return this->hopCount;
}

void ContentMsg::setHopCount(int hopCount)
{
    this->hopCount = hopCount;
}

char ContentMsg::getContent() const
{
    return this->content;
}

void ContentMsg::setContent(char content)
{
    this->content = content;
}

int ContentMsg::getChunk() const
{
    return this->chunk;
}

void ContentMsg::setChunk(int chunk)
{
    this->chunk = chunk;
}

int ContentMsg::getTcp_type() const
{
    return this->tcp_type;
}

void ContentMsg::setTcp_type(int tcp_type)
{
    this->tcp_type = tcp_type;
}

omnetpp::simtime_t ContentMsg::getC_average_chunk_arr() const
{
    return this->c_average_chunk_arr;
}

void ContentMsg::setC_average_chunk_arr(omnetpp::simtime_t c_average_chunk_arr)
{
    this->c_average_chunk_arr = c_average_chunk_arr;
}

omnetpp::simtime_t ContentMsg::getC_finish_dwnl_time() const
{
    return this->c_finish_dwnl_time;
}

void ContentMsg::setC_finish_dwnl_time(omnetpp::simtime_t c_finish_dwnl_time)
{
    this->c_finish_dwnl_time = c_finish_dwnl_time;
}

omnetpp::simtime_t ContentMsg::getC_total_stall_time() const
{
    return this->c_total_stall_time;
}

void ContentMsg::setC_total_stall_time(omnetpp::simtime_t c_total_stall_time)
{
    this->c_total_stall_time = c_total_stall_time;
}

int ContentMsg::getC_stall_count_size() const
{
    return this->c_stall_count_size;
}

void ContentMsg::setC_stall_count_size(int c_stall_count_size)
{
    this->c_stall_count_size = c_stall_count_size;
}

class ContentMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_source_num,
        FIELD_type,
        FIELD_destination,
        FIELD_hopCount,
        FIELD_content,
        FIELD_chunk,
        FIELD_tcp_type,
        FIELD_c_average_chunk_arr,
        FIELD_c_finish_dwnl_time,
        FIELD_c_total_stall_time,
        FIELD_c_stall_count_size,
    };
  public:
    ContentMsgDescriptor();
    virtual ~ContentMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(ContentMsgDescriptor)

ContentMsgDescriptor::ContentMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(ContentMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

ContentMsgDescriptor::~ContentMsgDescriptor()
{
    delete[] propertyNames;
}

bool ContentMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ContentMsg *>(obj)!=nullptr;
}

const char **ContentMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ContentMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ContentMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 11+base->getFieldCount() : 11;
}

unsigned int ContentMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_source_num
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_destination
        FD_ISEDITABLE,    // FIELD_hopCount
        FD_ISEDITABLE,    // FIELD_content
        FD_ISEDITABLE,    // FIELD_chunk
        FD_ISEDITABLE,    // FIELD_tcp_type
        FD_ISEDITABLE,    // FIELD_c_average_chunk_arr
        FD_ISEDITABLE,    // FIELD_c_finish_dwnl_time
        FD_ISEDITABLE,    // FIELD_c_total_stall_time
        FD_ISEDITABLE,    // FIELD_c_stall_count_size
    };
    return (field >= 0 && field < 11) ? fieldTypeFlags[field] : 0;
}

const char *ContentMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "source_num",
        "type",
        "destination",
        "hopCount",
        "content",
        "chunk",
        "tcp_type",
        "c_average_chunk_arr",
        "c_finish_dwnl_time",
        "c_total_stall_time",
        "c_stall_count_size",
    };
    return (field >= 0 && field < 11) ? fieldNames[field] : nullptr;
}

int ContentMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "source_num") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "type") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "destination") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "hopCount") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "content") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "chunk") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "tcp_type") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "c_average_chunk_arr") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "c_finish_dwnl_time") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "c_total_stall_time") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "c_stall_count_size") == 0) return baseIndex + 10;
    return base ? base->findField(fieldName) : -1;
}

const char *ContentMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_source_num
        "char",    // FIELD_type
        "int",    // FIELD_destination
        "int",    // FIELD_hopCount
        "char",    // FIELD_content
        "int",    // FIELD_chunk
        "int",    // FIELD_tcp_type
        "omnetpp::simtime_t",    // FIELD_c_average_chunk_arr
        "omnetpp::simtime_t",    // FIELD_c_finish_dwnl_time
        "omnetpp::simtime_t",    // FIELD_c_total_stall_time
        "int",    // FIELD_c_stall_count_size
    };
    return (field >= 0 && field < 11) ? fieldTypeStrings[field] : nullptr;
}

const char **ContentMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ContentMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ContentMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ContentMsg *pp = omnetpp::fromAnyPtr<ContentMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ContentMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ContentMsg *pp = omnetpp::fromAnyPtr<ContentMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ContentMsg'", field);
    }
}

const char *ContentMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ContentMsg *pp = omnetpp::fromAnyPtr<ContentMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ContentMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ContentMsg *pp = omnetpp::fromAnyPtr<ContentMsg>(object); (void)pp;
    switch (field) {
        case FIELD_source_num: return long2string(pp->getSource_num());
        case FIELD_type: return long2string(pp->getType());
        case FIELD_destination: return long2string(pp->getDestination());
        case FIELD_hopCount: return long2string(pp->getHopCount());
        case FIELD_content: return long2string(pp->getContent());
        case FIELD_chunk: return long2string(pp->getChunk());
        case FIELD_tcp_type: return long2string(pp->getTcp_type());
        case FIELD_c_average_chunk_arr: return simtime2string(pp->getC_average_chunk_arr());
        case FIELD_c_finish_dwnl_time: return simtime2string(pp->getC_finish_dwnl_time());
        case FIELD_c_total_stall_time: return simtime2string(pp->getC_total_stall_time());
        case FIELD_c_stall_count_size: return long2string(pp->getC_stall_count_size());
        default: return "";
    }
}

void ContentMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ContentMsg *pp = omnetpp::fromAnyPtr<ContentMsg>(object); (void)pp;
    switch (field) {
        case FIELD_source_num: pp->setSource_num(string2long(value)); break;
        case FIELD_type: pp->setType(string2long(value)); break;
        case FIELD_destination: pp->setDestination(string2long(value)); break;
        case FIELD_hopCount: pp->setHopCount(string2long(value)); break;
        case FIELD_content: pp->setContent(string2long(value)); break;
        case FIELD_chunk: pp->setChunk(string2long(value)); break;
        case FIELD_tcp_type: pp->setTcp_type(string2long(value)); break;
        case FIELD_c_average_chunk_arr: pp->setC_average_chunk_arr(string2simtime(value)); break;
        case FIELD_c_finish_dwnl_time: pp->setC_finish_dwnl_time(string2simtime(value)); break;
        case FIELD_c_total_stall_time: pp->setC_total_stall_time(string2simtime(value)); break;
        case FIELD_c_stall_count_size: pp->setC_stall_count_size(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ContentMsg'", field);
    }
}

omnetpp::cValue ContentMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ContentMsg *pp = omnetpp::fromAnyPtr<ContentMsg>(object); (void)pp;
    switch (field) {
        case FIELD_source_num: return pp->getSource_num();
        case FIELD_type: return pp->getType();
        case FIELD_destination: return pp->getDestination();
        case FIELD_hopCount: return pp->getHopCount();
        case FIELD_content: return pp->getContent();
        case FIELD_chunk: return pp->getChunk();
        case FIELD_tcp_type: return pp->getTcp_type();
        case FIELD_c_average_chunk_arr: return pp->getC_average_chunk_arr().dbl();
        case FIELD_c_finish_dwnl_time: return pp->getC_finish_dwnl_time().dbl();
        case FIELD_c_total_stall_time: return pp->getC_total_stall_time().dbl();
        case FIELD_c_stall_count_size: return pp->getC_stall_count_size();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ContentMsg' as cValue -- field index out of range?", field);
    }
}

void ContentMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ContentMsg *pp = omnetpp::fromAnyPtr<ContentMsg>(object); (void)pp;
    switch (field) {
        case FIELD_source_num: pp->setSource_num(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_type: pp->setType(omnetpp::checked_int_cast<char>(value.intValue())); break;
        case FIELD_destination: pp->setDestination(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_hopCount: pp->setHopCount(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_content: pp->setContent(omnetpp::checked_int_cast<char>(value.intValue())); break;
        case FIELD_chunk: pp->setChunk(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_tcp_type: pp->setTcp_type(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_c_average_chunk_arr: pp->setC_average_chunk_arr(value.doubleValue()); break;
        case FIELD_c_finish_dwnl_time: pp->setC_finish_dwnl_time(value.doubleValue()); break;
        case FIELD_c_total_stall_time: pp->setC_total_stall_time(value.doubleValue()); break;
        case FIELD_c_stall_count_size: pp->setC_stall_count_size(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ContentMsg'", field);
    }
}

const char *ContentMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr ContentMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ContentMsg *pp = omnetpp::fromAnyPtr<ContentMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ContentMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ContentMsg *pp = omnetpp::fromAnyPtr<ContentMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ContentMsg'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

