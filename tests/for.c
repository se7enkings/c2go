#include <stdio.h>
#include "tests.h"

int main()
{
    plan(40);

    int i = 0;

    diag("Missing init");
    for (; i < 3; i++)
        pass("%d", i);

    diag("CompountStmt");
    for (i = 0; i < 3; i++)
    {
        pass("%d", i);
    }

    diag("Not CompountStmt");
    for (i = 0; i < 3; i++)
        pass("%d", i);

    diag("Infinite loop");
    int j = 0;
    for (;;)
    {
        pass("%d", j);
        j++;
        if (j > 3)
            break;
    }

    diag("continue");
    i = 0;
    j = 0;
    for (;;)
    {
        pass("%d %d", i, j);
        i++;
        if (i < 3)
            continue;
        j++;
        if (j > 3)
            break;
    }

	diag("big initialization 1");
	for ( i = 0, j = 0 ; i < 3 ; i++){
		pass("%d %d", i, j);
	}
	
	diag("big initialization 2");
	for ( i = 0, j = 0 ; i < 3 ; ){
		pass("%d %d", i, j);
		i++;
		j++;
	}

	diag("big increment");
	i = 0;
	j = 0;
	for (;i < 3;i++,j++){
		pass("%d %d", i, j);
	}

	diag("big condition");
	i = -1;
	j = 0;
	for(;i++,j<3;){
		pass("%d %d", i, j);
		j++;
	}

	diag("Without body and with 2 and more increments");
	for(i = 0, j = 0; i < 2; j++,i++);
	pass("%d",i)

	diag("Without body and with 2 and more conditions");
	for(i = 0, j = 0; j++,i++,i < 2; );
	pass("%d",i)

	diag("initialization inside for");
	for(int h = 0;h < 3; h++)
		pass("%d",h)
	
	diag("double initialization inside for");
	for(int f = 0 , g = 0;g < 2 || f < 2; g++, f++){
		pass("%d",f)
		pass("%d",g)
	}

    done_testing();
}
