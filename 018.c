#include<stdio.h>
#include<math.h>



int main()
{
	double T, L,X, Y;
	scanf("%lf", &T);
	scanf("%lf %lf %lf",&L, &X, &Y);

	int Q;
	scanf("%d", &Q);
	double t;

	for (int i = 0; i < Q; i++)
	{
		scanf("%lf", &t);

		//観覧車の座標
		const double PI = acos(-1.0);
		double theata = 2.0 * PI * t / T;

		double y = (L / 2.0) * cos(theata + PI / 2.0);
		double z = (L / 2.0) -(L/2.0)*cos(theata);

		double horizontal = sqrt(X * X +(Y - y) * (Y - y));
		double ans = atan2(z,horizontal)*180/PI;

		printf("%.10lf\n",ans);
	}

	return 0;


}
