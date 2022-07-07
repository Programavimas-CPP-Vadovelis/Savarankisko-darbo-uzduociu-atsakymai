void ascending( double x[], int n, bool flag ){
	//
	// x - masyvas; programos darbo metu
	//     išrūšiuojamas didėjimo tvarka
	// n - elementų skaičius masyve
	// flag - = true  - rūšiuoti didėjančiai,
	//        = false - rūšiuoti mažėjančiai
	//
	double laik;
	for( size_t i=0; i<n-1; i++ )
		for( size_t j=i+1; j<n; j++ ){
			if( flag && x[i]>x[j] ){
				laik = x[i];
				x[i] = x[j];
				x[j] = laik;
			}
			if( !flag && x[i]<x[j] ){
				laik = x[i];
				x[i] = x[j];
				x[j] = laik;
			}
		}
}
//
//
void ascending( int x[], int n, bool flag ){
	//
	// x - masyvas; programos darbo metu
	//     išrūšiuojamas didėjimo tvarka
	// n - elementų skaičius masyve
	// flag - = true  - rūšiuoti didėjančiai,
	//        = false - rūšiuoti mažėjančiai
	//
	int laik;
	for( size_t i=0; i<n-1; i++ )
		for( size_t j=i+1; j<n; j++ ){
			if( flag && x[i]>x[j] ){
				laik = x[i];
				x[i] = x[j];
				x[j] = laik;
			}
			if( !flag && x[i]<x[j] ){
				laik = x[i];
				x[i] = x[j];
				x[j] = laik;
			}
		}
}
