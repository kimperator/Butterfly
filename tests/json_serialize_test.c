/*  
    Copyright (C) 2011 Daniel Waterworth
    
    This file is part of Butterfly.
    
    Butterfly is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Butterfly is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <math.h>
#include <stdlib.h>

#include "json_serialize_test.h"
#include "object.h"

START_TEST (test_null) {
    object *obj = object_none();
    U_STRING(none_str, "null", 4);
    fail_unless(u_strcmp(none_str, object_to_json(obj, false)) == 0, NULL);
} END_TEST

START_TEST (test_true) {
    object *obj = object_bool(true);
    U_STRING(true_str, "true", 4);
    fail_unless(u_strcmp(true_str, object_to_json(obj, false)) == 0, NULL);
} END_TEST

START_TEST (test_false) {
    object *obj = object_bool(false);
    U_STRING(false_str, "false", 5);
    fail_unless(u_strcmp(false_str, object_to_json(obj, false)) == 0, NULL);
} END_TEST

START_TEST (test_int_1) {
    object *obj = object_int(5234);
    U_STRING(int_str, "5234", 4);
    UChar *res = object_to_json(obj, false);
    fail_unless(u_strcmp(int_str, res) == 0, NULL);
} END_TEST

START_TEST (test_int_2) {
    object *obj = object_int(-5234);
    U_STRING(int_str, "-5234", 5);
    UChar *res = object_to_json(obj, false);
    fail_unless(u_strcmp(int_str, res) == 0, NULL);
} END_TEST

START_TEST (test_int_3) {
    object *obj = object_int(0);
    U_STRING(int_str, "0", 1);
    fail_unless(u_strcmp(int_str, object_to_json(obj, false)) == 0, NULL);
} END_TEST

START_TEST (test_str_1) {
    U_STRING(str_test, "test\n\"\\", 7);
    object *obj = object_str(str_test);
    UChar *json_str = object_to_json(obj, false);
    U_STRING(json_actual, "\"test\\n\\\"\\\\\"", 12);
    fail_unless(u_strcmp(json_str, json_actual) == 0, NULL);
} END_TEST

TCase *json_serialize_test_case() {
    TCase *tc = tcase_create("json_serialization");
    tcase_add_test(tc, test_null);
    tcase_add_test(tc, test_true);
    tcase_add_test(tc, test_false);
    tcase_add_test(tc, test_int_1);
    tcase_add_test(tc, test_int_2);
    tcase_add_test(tc, test_int_3);
    tcase_add_test(tc, test_str_1);
    return tc;
}
