mod question_2769;
mod question_2824;

#[cfg(test)]
mod algo_test {
    use super::*;

    #[test]
    fn question_2769_works() {
        let mut res = question_2769::Solution::the_maximum_achievable_x(4, 1);
        assert_eq!(res, 6);

        res = question_2769::Solution::the_maximum_achievable_x(3, 2);
        assert_eq!(res, 7);
    }

    #[test]
    fn question_2824_works() {
        let mut nums = vec![-1, 1, 2, 3, 1];
        let mut res = question_2824::Solution::count_pairs(nums, 2);
        println!("------------>>>>>>>>>>>>>>>: {}", res);
        assert_eq!(res, 3);

        nums = vec![-6, 2, 5, -2, -7, -1, 3];
        res = question_2824::Solution::count_pairs(nums, -2);
        println!("------------>>>>>>>>>>>>>>>: {}", res);
        assert_eq!(res, 10);
    }
}
