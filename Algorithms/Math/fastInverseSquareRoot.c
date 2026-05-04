//
// This algorithm is a fast way of approximating 1/sqrt(x). It can be used to normalize the length
// of a vector (i.e. scale it to length 1) using the formula v * 1/sqrt(x^2 + y^2 + z^2).
// Normalizing vectors is used a lot in 3D Graphics.
//
// This specific algorithm was popularized by the game Quake III for its infamous
// documentation ("evil floating point bit level hacking", "what the fuck?"). It works by using clever typecasting
// to reinterpret the bits of a float into a long, then using a bitshift and a magic number (sqrt(2^127)) to approximate,
// then casting back. After that, one iteration of newtons method is used to refine the result
//
// TAGS
// domain/math
// domain/visual
// paradigm/bit-manipulation
// 

float inverseSquareRoot(float number) {
    const float root_2_pow_127 = 0x5f3759df; // approximation for sqrt(2^127)

    // typecasting trick:
    // directly casting float to long would try to keep the numerical value. casting to a pointer and 
    // dereferencing it keeps the bits the same, but allows you to treat it as a long
    // bitshifting and subtracting the magic number yields an approximation for math reasons
	float y  = number;
	long temp  = *(long*) &y; // reinterpret bits as long
	temp  = root_2_pow_127 - ( temp >> 1 ); // math trick
	y  = * (float*) &temp;  // reinterpret as float again

    /// newton iteration to refine result
	y  *= ( 1.5F - ( number * 0.5F * y * y ) );

	return y; 
}