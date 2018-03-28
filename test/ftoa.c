#include <math.h>
#include <sccs.h>

#define MAXEXP		308
#define	DEFPREC		6

/*
**  FLOATING POINT TO ASCII CONVERSION
**
**	'Value' is converted to an ascii character string and stored
**	into 'ascii'.  Ascii should have room for at least 'width' + 1
**	characters.  'Width' is the width of the output field (max).
**	'Prec' is the number of characters to put after the decimal
**	point.  The format of the output string is controlled by
**	'format'.
**
**	'Format' can be:
**		e or E: "E" format output
**		f or F:  "F" format output
**		g or G:  "F" format output if it will fit, otherwise
**			use "E" format.
**		n or N:  same as G, but decimal points will not always
**			be aligned.
**
**	If 'format' is upper case, the "E" comes out in upper case;
**	otherwise it comes out in lower case.
**
**	When the field width is not big enough, it fills the field with
**	stars ("*****") and returns zero.  Normal return is the width
**	of the output field (sometimes shorter than 'width').
*/

#define	PADSIZE	16		/* pad chunk size */
static char zeroes[PADSIZE] =
	{'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};

	/*
	 * BEWARE, these `return (0);' on error, and PAD uses `n'.
	 */
#define	PAD(howmany, with) { \
	if ((n = (howmany)) > 0) { \
		while (n > PADSIZE) { \
			PRINT(with, PADSIZE); \
			n -= PADSIZE; \
		} \
		PRINT(with, n); \
	} \
}

#define PRINT(ptr, cnt) { \
	if ((len +  cnt) > width) { \
		while (width-- > 0) \
			*ascii++ = '*'; \
		*ascii = '\0'; \
		return (0); \
	} \
	memcpy(ascii + len, ptr, cnt), len += cnt; \
}

/*
 * Macros for converting digits to letters and vice versa
 */
#define	to_char(n)	((n) + '0')

/*
 * Flags used during conversion.
 */
#define	ALT		0x001		/* alternate form */
#define FPT		0x100		/* Floating point number */

static char *cvt __P((double, int, int, char *, int *, int, int *));
static int exponent __P((char *, int, int));

int		ftoa(double value, char *ascii, int width, int prec, char ch)
{
	register int	len;		/* length of ascii */
	register int	n;			/* handy integer (short term usage) */
	register char	*cp;		/* handy char pointer (short term usage) */
	register int	flags;		/* flags as above */
	int				ret;		/* return value accumulator */
	char			sign;		/* sign prefix (' ', '+', '-', or \0) */
	char			softsign;	/* temporary negative sign for floats */
	double			_double;	/* double precision arguments %[eEfgG] */
	int				expt;		/* integer value of exponent */
	int				expsize;	/* character count for expstr */
	int				ndig;		/* actual number of digits returned by cvt */
	int				dprec;		/* a copy of prec if [diouxX], 0 otherwise */
	char			expstr[7];	/* buffer for exponent string */
	int				fieldsz;	/* field size expanded by sign, etc */
	int				realsz;		/* field size expanded by dprec */
	int				size;		/* size of converted field or string */
	char			ox[2];		/* space for 0x hex-prefix */

	len = 0;
	flags = 0;
	dprec = 0;
	sign = '\0';
	if (ch == 'F') ch = 'f';
	switch (ch) {
		case 'e':		/* anomalous precision */
		case 'E':
			prec = (prec == -1) ? DEFPREC + 1 : prec + 1;
			/* FALLTHROUGH */
			goto fp_begin;
		default:
		case 'f':		/* always print trailing zeroes */
			if (prec != 0)
				flags |= ALT;
		case 'n':
		case 'N':
		case 'g':
		case 'G':
			if (prec == -1)
				prec = DEFPREC;
fp_begin:		_double = value;
			/* do this before tricky precision changes */
			if (isinf(_double)) {
				if (_double < 0)
					sign = '-';
				cp = "Inf";
				size = 3;
				break;
			}
			if (isnan(_double)) {
				cp = "NaN";
				size = 3;
				break;
			}
			flags |= FPT;
			cp = cvt(_double, prec, flags, &softsign,
				&expt, ch, &ndig);
			if (ch == 'g' | ch == 'G') {
				if (expt <= -4 || expt > prec)
					ch = (ch == 'g') ? 'e' : 'E';
				else
					ch = 'g';
			}
			if (ch <= 'e') {	/* 'e' or 'E' fmt */
				--expt;
				expsize = exponent(expstr, expt, ch);
				size = expsize + ndig;
				if (ndig > 1 || flags & ALT)
					++size;
			} else if (ch == 'f') {		/* f fmt */
				if (expt > 0) {
					size = expt;
					if (prec || flags & ALT)
						size += prec + 1;
				} else	/* "0.X" */
					size = prec + 2;
			} else if (expt >= ndig) {	/* fixed g fmt */
				size = expt;
				if (flags & ALT)
					++size;
			} else
				size = ndig + (expt > 0 ?
					1 : 2 - expt);

			if (softsign)
				sign = '-';
			break;
		}


		/*
		 * All reasonable formats wind up here.  At this point, `cp'
		 * points to a string which (if not flags&LADJUST) should be
		 * padded out to `width' places.  If flags&ZEROPAD, it should
		 * first be prefixed by any sign or other prefix; otherwise,
		 * it should be blank padded before the prefix is emitted.
		 * After any left-hand padding and prefixing, emit zeroes
		 * required by a decimal [diouxX] precision, then print the
		 * string proper, then emit zeroes required by any leftover
		 * floating precision; finally, if LADJUST, pad with blanks.
		 *
		 * Compute actual size, so we know how much to pad.
		 * fieldsz excludes decimal prec; realsz includes it.
		 */
		fieldsz = size;
		if (sign)
			fieldsz++;
/*
		realsz = dprec > fieldsz ? dprec : fieldsz;
*/
		realsz = fieldsz;

		/* prefix */
		if (sign)
			PRINT(&sign, 1);

		/* leading zeroes from decimal precision */
/*
		PAD(dprec - fieldsz, zeroes);
*/

		/* the string or number proper */
		if ((flags & FPT) == 0) {
			PRINT(cp, size);
		} else {	/* glue together f_p fragments */
			if (ch >= 'f') {	/* 'f' or 'g' */
				if (_double == 0) {
				/* kludge for __dtoa irregularity */
					if (prec == 0 ||
					    (flags & ALT) == 0) {
						PRINT("0", 1);
					} else {
						PRINT("0.", 2);
						PAD(ndig - 1, zeroes);
					}
				} else if (expt <= 0) {
					PRINT("0.", 2);
					PAD(-expt, zeroes);
					PRINT(cp, ndig);
				} else if (expt >= ndig) {
					PRINT(cp, ndig);
					PAD(expt - ndig, zeroes);
					if (flags & ALT)
						PRINT(".", 1);
				} else {
					PRINT(cp, expt);
					cp += expt;
					PRINT(".", 1);
					PRINT(cp, ndig-expt);
				}
			} else {	/* 'e' or 'E' */
				if (ndig > 1 || flags & ALT) {
					ox[0] = *cp++;
					ox[1] = '.';
					PRINT(ox, 2);
					if (_double || flags & ALT == 0) {
						PRINT(cp, ndig-1);
					} else	/* 0.[0..] */
						/* __dtoa irregularity */
						PAD(ndig - 1, zeroes);
				} else	/* XeYYY */
					PRINT(cp, 1);
				PRINT(expstr, expsize);
			}
		}
		/* finally, adjust ret */
		ret += width > realsz ? width : realsz;
	ascii[len] = '\0';
	return (ret);
	/* NOTREACHED */
}

extern char *__dtoa __P((double, int, int, int *, int *, char **));

static char *
cvt(value, ndigits, flags, sign, decpt, ch, length)
	double value;
	int ndigits, flags, *decpt, ch, *length;
	char *sign;
{
	int mode, dsgn;
	char *digits, *bp, *rve;

	if (ch == 'f')
		mode = 3;
	else {
		mode = 2;
	}
	if (value < 0) {
		value = -value;
		*sign = '-';
	} else
		*sign = '\000';
	digits = __dtoa(value, mode, ndigits, decpt, &dsgn, &rve);
	if (flags & ALT) {	/* Print trailing zeros */
		bp = digits + ndigits;
		if (ch == 'f') {
			if (*digits == '0' && value)
				*decpt = -ndigits + 1;
			bp += *decpt;
		}
		if (value == 0)	/* kludge for __dtoa irregularity */
			rve = bp;
		while (rve < bp)
			*rve++ = '0';
	}
	*length = rve - digits;
	return (digits);
}

static int
exponent(p0, exp, fmtch)
	char *p0;
	int exp, fmtch;
{
	register char *p, *t;
	char expbuf[MAXEXP];

	p = p0;
	*p++ = fmtch;
	if (exp < 0) {
		exp = -exp;
		*p++ = '-';
	}
	else
		*p++ = '+';
	t = expbuf + MAXEXP;
	if (exp > 9) {
		do {
			*--t = to_char(exp % 10);
		} while ((exp /= 10) > 9);
		*--t = to_char(exp);
		for (; t < expbuf + MAXEXP; *p++ = *t++);
	}
	else {
		*p++ = '0';
		*p++ = to_char(exp);
	}
	return (p - p0);
}
