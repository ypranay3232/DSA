    for(int row=0;row<n;row=row+1){
        // inner loop

        int cols;
        for(;cols<row+1;cols=cols+1){
            int answer = cols + 1; //to increment the number by +1 so that we can print a character
            char ch = answer + 'A'-1;
            cout<<ch;
        }
        // Now to print the reverse counting ! 
        for(int cols=row;cols>=1;cols=cols-1){
            int answer = cols;
            char ch = answer + 'A'-1;
            cout<<ch;
        }
        cout<<endl;
    }