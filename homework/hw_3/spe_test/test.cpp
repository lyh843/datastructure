#include <iostream>
#include "answer1.hpp"
#include "answer2.hpp"

int main(){
    for(int i1 = 1; i1 <= 15; i1++){
        for(int i2 = 1; i2 <= 15; i2++){
            for(int i3 = 1; i3 <= 15; i3++){
                for(int i4 = 1; i4 <= 15; i4++){
                    for(int i5 = 1; i5 <= 15; i5++){
                        for(int i6 = 1; i6 <= 15; i6++){
                            for(int i7 = 1; i7 <= 15; i7++){
                                for(int i8 = 1; i8 <= 15; i8++){
                                    for(int i9 = 1; i9 <= 15; i9++){
                                        int arr[10] = {0, i1, i2, i3, i4, i5, i6, i7, i8, i9};
                                        int result1 = answer1(9, 3, 6, arr);
                                        int result2 = answer2(9, 3, 6, arr);
                                        if(result1 != result2){
                                            for(int i = 1; i <= 10; i++){
                                                cout << arr[i] << " ";
                                            }
                                            cout << "\n";
                                            return 0;
                                        }
                                    }
                                }
                            }

                        }
                    }
                }
            }
        }
    }
    cout << "True\n";
    return 0;
}