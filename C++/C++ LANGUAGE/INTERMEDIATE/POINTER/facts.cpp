
    //NOTE:- . An expression doesn't get evaluated inside sizeof operator.

    struct vectord {
    short len;    // there must be at least one other data member
    double arr[]; // the flexible array member must be last
    // The compiler may reserve extra padding space here, like it can between struct members
};