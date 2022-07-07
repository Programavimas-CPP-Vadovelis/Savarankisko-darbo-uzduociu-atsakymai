void swap(double x[], int n, double y){
	//
	// x - masyvas
	// n - elementų skaičius masyve
	// y - reikšmė, kuriai ieškosime artimiausio masyvo elemento
	//
	double d = abs( x[0]-y );  // prielaidos
	int nr = 0;
	for( size_t i=1; i<n; i++ ){
		if( abs( x[i]-y ) < d ){
			nr = i;
			d = abs( x[i]-y );
		}
	}
	//
	x[nr] = y;
}
//
//
void swap(int x[], int n, int y){
	//
	// x - masyvas
	// n - elementų skaičius masyve
	// y - reikšmė, kuriai ieškosime artimiausio masyvo elemento
	//
	int d = abs( x[0]-y );  // prielaidos
	int nr = 0;
	for( size_t i=1; i<n; i++ ){
		if( abs( x[i]-y ) < d ){
			nr = i;
			d = abs( x[i]-y );
		}
	}
	//
	x[nr] = y;
}
