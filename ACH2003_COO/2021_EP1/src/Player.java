import java.awt.*;

/**
	Esta classe representa os jogadores (players) do jogo. A classe princial do jogo (Pong)
	instancia dois objetos deste tipo quando a execução é iniciada.
*/

public class Player {
	private double cx;
	private double cy;
	private double width;
	private double height;
	private Color color;
	private String id;
	private double [] v_limit;
	private double csuperior;
	private double cinferior;
	private double speed;

	/**
		Construtor da classe Player.

		@param cx coordenada x da posição inicial do player (centro do retangulo que o representa).
		@param cy coordenada y da posição inicial do player (centro do retangulo que o representa).
		@param width largura do retangulo que representa o player.
		@param height altura do retangulo que representa o player.
		@param color cor do player.
		@param id uma string que identifica o player
		@param v_limit um array de double contendo dois valores (em pixels) que determinam os limites verticais da área útil da quadra.
		@param speed velocidade do movimento vertical do player (em pixels por millisegundo).
	*/

	public Player(double cx, double cy, double width, double height, Color color, String id, double [] v_limit, double speed){
		this.cx = cx;
		this.cy = cy;
		this.width = width;
		this.height = height;
		this.color = color;
		this.id = id;
		this.v_limit = v_limit;
		this.speed = speed;

		if (v_limit[0] > v_limit[1]) {
			this.csuperior = v_limit[0] - height/2 ;
			this.cinferior = v_limit[1] + height/2 ;
		}
		else {
			this.csuperior = v_limit[1] - height/2 ;
			this.cinferior = v_limit[0] + height/2 ;
		}
	}
	/**
		Método chamado sempre que o player precisa ser (re)desenhado.
	*/
	public void draw(){
		GameLib.setColor(color);
		GameLib.fillRect(cx, cy, width, height);
	}


	/**
		Método chamado quando se deseja mover o player para cima.
		Este método é chamado sempre que a tecla associada à ação
		de mover o player para cima estiver pressionada.

		@param delta quantidade de millisegundos que se passou entre o ciclo anterior de atualização do jogo e o atual.
	*/
	public void moveUp(long delta){
		double aux = cy - speed * delta;
		if(aux < cinferior) cy = cinferior;
		else cy = aux;
	}



	/**
		Método chamado quando se deseja mover o player para baixo.
		Este método é chamado sempre que a tecla associada à ação
		de mover o player para baixo estiver pressionada.

		@param delta quantidade de millisegundos que se passou entre o ciclo anterior de atualização do jogo e o atual.
	*/
	public void moveDown(long delta){
		double aux = cy + speed * delta;
		if(aux > csuperior) cy = csuperior;
		else cy = aux;
	}


	/**
		Método que devolve a string de identificação do player.
		@return a String de indentificação.
	*/
	public String getId() {
		return id;
	}



	/**
		Método que devolve a largura do retangulo que representa o player.
		@return um double com o valor da largura.
	*/

	public double getWidth() {
		return width;
	}



	/**
		Método que devolve a algura do retangulo que representa o player.
		@return um double com o valor da altura.
	*/
	public double getHeight() {
		return height;
	}


	/**
		Método que devolve a coordenada x do centro do retangulo que representa o player.
		@return o valor double da coordenada x.
	*/

	public double getCx() {
		return cx;
	}

	/**
		Método que devolve a coordenada y do centro do retangulo que representa o player.
		@return o valor double da coordenada y.
	*/

	public double getCy() {
		return cy;
	}
}
