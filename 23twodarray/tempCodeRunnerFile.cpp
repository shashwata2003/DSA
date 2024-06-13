for (int i = lastrow; count < total && i >= firstrow; i--) {
            ans.push_back(arr[i][firstcol]);
            count++;
        }
        firstcol++;