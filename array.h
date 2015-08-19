/*
Copyright (c) 2015-2016, Intel Corporation

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#pragma once

#include "type.h"

extern unsigned int MAX_ARRAY_SIZE;

class Array {
    public:
        explicit Array () : type(NULL) {};
        explicit Array (std::string _name, unsigned int _type_id, unsigned int _size);
        Array (const Array& _op);
        Array& operator=(const Array& _op);
        ~Array ();
        std::string get_name () const;
        void set_size (unsigned int _size);
        unsigned int get_size () const;
        unsigned int get_type_id () const;
        std::string get_type_name () const;
        void set_max_value (uint64_t _max_val);
        uint64_t get_max_value () const;
        void set_min_value (uint64_t _min_val);
        uint64_t get_min_value () const;
        void set_bound_value (std::vector<uint64_t> bval);
        std::vector<uint64_t> get_bound_value () const;
        bool get_is_fp () const;
        bool get_is_signed () const;
        std::string emit_usage ();
        static Array get_rand_obj ();
        void dbg_dump ();

    private:
        std::string name;
        unsigned int size;
        Type* type;
};
