
/**
 * repr�sente la session de dessin entreprise par un client distant.
 *
 * Effectue principalement les op�rations suivantes :
 *
 * ouvre une fen�tre awt (Frame) pour dessiner dessus (les coordonn�es de la fen�tre sont indiqu�es par le client).
 * puis ex�cute sur la fen�tre ouverte tous les ordres de trac� du client distant.
 *
 * fonctionne dans un thread s�par� du thread principal.
 *
 * */
import java.net.Socket;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.SocketException;


public class SessionDessin extends Thread
{
	Socket _socket;
	BufferedReader _fluxEntrant;
	int _nombreClients;
	/**
	 * cr�e la session de dessin avec le client distant connect� sur socket
	 * @throws IOException
	 *
	 * */
	public SessionDessin(Socket socket, int nombreClients) throws IOException
	{
		_socket = socket;
		_nombreClients = nombreClients;
		_fluxEntrant = new BufferedReader(new InputStreamReader(_socket.getInputStream()));
	}

	public void run()
	{
		String requete = "";
		try
		{
			while (_fluxEntrant.ready() && !isInterrupted())
			{
				requete += _fluxEntrant.readLine() + "\n";
			}
		}
		catch (IOException e)
		{
			System.err.println("Impossible de lire dans le socket du client ");
		}

		try
		{
			_socket.shutdownInput();
			_socket.close();
		}
		catch (IOException e)
		{
			System.err.println("Impossible de fermer le socket du client ");
		}

		System.out.println("Re�u :\n" + requete + "\n");
		try {
			new CadreDessin("Dessin n�" + _nombreClients, requete);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}


}

