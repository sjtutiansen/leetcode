#include "leet_code.h"

int main(int argc, char *argv[]){
    int nums[3] = {3,2,3};
    int numsSize = 3,target = 6;
    int* ans;
    ans = twoSum(nums,numsSize,target);
    printf("%d %d",ans[0],ans[1]);
    free(ans);
    system("pause");
    return 0;
}
