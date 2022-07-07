void derivative( double tol, double x, double& d ){
	//
	// tol - funkcijos išvestinės skaičiavimo tikslumas
	// x - taškas, kuriame skaičiuojama išvestinė
	// d - apytikrė funkcijos išvestinė taške x
	//
	double ds, dn;  // išvestinės: prie grubesnio ir smulkesnio žingsnių
	double xk, xd, fk, fd; // abscisės, funkcijos reikšmės
	//
	double dx = 5./100.; // pradinis diferencijavimo žingsnis 1.e-2
	                    // - cikle bus padaugintas iš 5 
	//
	ds = 0.;    // =0 - kad prasisuktų bent viena iteracija

	for( ; ; ){ // begalinis ciklas tikslumui pasiekti
		dx/=5.;
		xk = x - dx/2.;
		xd = x + dx/2.;
		fk = xk*xk*sin( xk );
		fd = xd*xd*sin( xd );
		dn = ( fd - fk ) / dx;
		if( abs(dn-ds) < tol ) // jei tikslumas pasiektas - 
			break;     // baigti ciklą
		else
			ds = dn;  // jei ne - kartoti ciklą
	}  
	//
	d = dn;
	//	
}
