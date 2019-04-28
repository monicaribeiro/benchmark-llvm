#include "quicksort.h"
#pragma DATA_ALIGN(x, 8);  
int main()
{
	int i;
	int teste;
	int results[] = {-50000,-49999,-49997,-49985,-49964,-49962,-49944,-49939,-49915,-49880,-49878,-49867,-49866,-49841,-49821,-49817,-49814,-49813,-49796,-49786,-49783,-49780,-49761,-49733,-49718,-49714,-49712,-49694,-49692,-49679,-49678,-49677,-49662,-49643,-49616,-49612,-49589,-49560,-49530,-49527,-49526,-49524,-49509,-49485,-49470,-49457,-49451,-49442,-49441,-49440,-49430,-49423,-49422,-49414,-49395,-49393,-49388,-49375,-49371,-49340,-49318,-49313,-49296,-49274,-49268,-49257,-49256,-49207,-49199,-49192,-49190,-49184,-49183,-49179,-49176,-49170,-49169,-49141,-49130,-49122,-49117,-49110,-49079,-49073,-49069,-49046,-49033,-49021,-49018,-49012,-48999,-48996,-48994,-48968,-48955,-48951,-48919,-48915,-48908,-48907};
	#pragma monitor start	
	for (i = 0; i < 10; i++) {
            teste = quicksort(i);
            // printf("indo :%d\n", i);
            if(teste != results[i]){
            	// printf("lugar %d: %d | %d\n", i, results[i], teste);
            	return 1;
            }
	}
	return 10;
	#pragma monitor stop
}