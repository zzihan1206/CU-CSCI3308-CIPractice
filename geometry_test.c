#include <stdlib.h>
#include <check.h>

#include "geometry.h"

START_TEST(test_2d_eq)
{
    coord_2d_t a;
    coord_2d_t b;

    a.x = b.x = 0;
    a.y = b.y = 0;
    ck_assert(coord_2d_eq(&a, &b));

    a.x = b.x = 9.99;
    a.y = b.y = 9.99;
    ck_assert(coord_2d_eq(&a, &b));

    a.x = b.x = 3.33;
    a.y = b.y = 9.99;
    ck_assert(coord_2d_eq(&a, &b));

    a.x = 3.33;
    a.y = 9.99;
    a.x = 3.33;
    a.y = 10.99;
    ck_assert(!coord_2d_eq(&a, &b));

    a.x = 3.33;
    a.y = 9.99;
    a.x = 2.33;
    a.y = 9.99;
    ck_assert(!coord_2d_eq(&a, &b));

    a.x = 1.11;
    a.y = 2.22;
    a.x = 7.77;
    a.y = 8.88;
    ck_assert(!coord_2d_eq(&a, &b));

}
END_TEST

Suite* coord_2d_suite(void)
{

    Suite* s = suite_create("coord_2d");

    TCase* tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_2d_eq);

    suite_add_tcase(s, tc_core);

    return s;

}

int main(void){

    int failed = 0;
    Suite* s = coord_2d_suite();
    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (failed ? EXIT_FAILURE : EXIT_SUCCESS);

}
