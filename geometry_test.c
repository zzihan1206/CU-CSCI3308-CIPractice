#include <stdlib.h>
#include <check.h>

#include "geometry.h"

/* coord_2d_eq Test */
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
    b.x = 3.33;
    b.y = 10.99;
    ck_assert(!coord_2d_eq(&a, &b));

    a.x = 3.33;
    a.y = 9.99;
    b.x = 2.33;
    b.y = 9.99;
    ck_assert(!coord_2d_eq(&a, &b));

    a.x = 1.11;
    a.y = 2.22;
    b.x = 7.77;
    b.y = 8.88;
    ck_assert(!coord_2d_eq(&a, &b));

}
END_TEST

/* coord_2d_dist Test */
START_TEST(test_2d_dist)
{
    coord_2d_t a;
    coord_2d_t b;

    a.x = b.x = 0;
    a.y = b.y = 0;
    ck_assert(coord_2d_dist(&a, &b) == 0.0);

    a.x = 0;
    a.y = 0;
    b.x = 3;
    b.y = 0;
    ck_assert(coord_2d_dist(&a, &b) == 3.0);

    a.x = 0;
    a.y = 0;
    b.x = 0;
    b.y = 3;
    ck_assert(coord_2d_dist(&a, &b) == 3.0);

}
END_TEST

Suite* coord_2d_suite(void)
{

    Suite* s = suite_create("coord_2d");

    TCase* tc_2d_eq = tcase_create("coord_2d_eq");
    tcase_add_test(tc_2d_eq, test_2d_eq);

    TCase* tc_2d_dist = tcase_create("coord_2d_dist");
    tcase_add_test(tc_2d_dist, test_2d_dist);

    suite_add_tcase(s, tc_2d_eq);
    suite_add_tcase(s, tc_2d_dist);

    return s;

}

int main(void){

    int failed = 0;
    Suite* s = coord_2d_suite();
    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (failed ? EXIT_FAILURE : EXIT_SUCCESS);

}
