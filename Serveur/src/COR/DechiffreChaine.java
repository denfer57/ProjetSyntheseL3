package COR;
import java.awt.Color;

public class DechiffreChaine
{
	public static double[] dechiffrePoint(String str)
	{
		str = str.substring(1, str.length() - 1);
		String[] p = str.split(",");
		double[] point =
		{
			Double.parseDouble(p[0].trim()),
			Double.parseDouble(p[1].trim())
		};
		return point;
	}

	public static Color dechiffreCouleur(String str)
	{
		// on essaye de convertir en une couleur
		try
		{
			String r = str.substring(0, 3);
			String v = str.substring(4, 7);
			String b = str.substring(8, 11);
			return new Color(Integer.valueOf(r), Integer.valueOf(v), Integer.valueOf(b));
		}
		catch (Exception e)
		{
			return Color.BLUE;
		}
	}
}