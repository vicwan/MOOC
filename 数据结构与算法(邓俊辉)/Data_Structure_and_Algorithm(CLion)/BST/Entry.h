//
// Created by 万伟琦 on 2017/12/20.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_CLION_ENTRY_H
#define DATA_STRUCTURE_AND_ALGORITHM_CLION_ENTRY_H

/*词条数据结构, BST 中每个节点都是一个词条*/
template <typename K, typename V>
struct Entry {
    K _key;
    V _value;
public:
    /*构造函数*/
    Entry( K k = K(), V v = V() ):_key(k), _value(v) {};
    /*复制构造函数*/
    Entry( Entry<K, V> const& e ): _key(e._key), _value(e._value) {};

    /*判等和比较*/
    bool operator < ( Entry<K, V> const& e ) { return _key < e._key; }
    bool operator > ( Entry<K, V> const& e ) { return _key > e._key; }
    bool operator == ( Entry<K, V> const& e ) { return _key == e._key; }
    bool operator != ( Entry<K, V> const& e ) { return _key != e._key; }
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_CLION_ENTRY_H
